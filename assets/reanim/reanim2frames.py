import xml.etree.ElementTree as ET
from collections import defaultdict
from PIL import Image
import os

# ---------- 配置项 ----------
reanim_path = "PeaShooter.reanim"
image_folder = os.path.dirname(reanim_path)
output_folder = "../frames"
canvas_size = (400, 400)
fps = 12  # 默认值，会被文件中的 <fps> 覆盖

# ---------- 图像 ID 映射表 ----------
image_map = {
    "IMAGE_REANIM_PEASHOOTER_BACKLEAF": "PeaShooter_backleaf.png",
    "IMAGE_REANIM_PEASHOOTER_BACKLEAF_LEFTTIP": "PeaShooter_backleaf_lefttip.png",
    "IMAGE_REANIM_PEASHOOTER_BACKLEAF_RIGHTTIP": "PeaShooter_backleaf_righttip.png",
    "IMAGE_REANIM_PEASHOOTER_BLINK1": "PeaShooter_blink1.png",
    "IMAGE_REANIM_PEASHOOTER_BLINK2": "PeaShooter_blink2.png",
    "IMAGE_REANIM_PEASHOOTER_EYEBROW": "PeaShooter_eyebrow.png",
    "IMAGE_REANIM_PEASHOOTER_FRONTLEAF": "PeaShooter_frontleaf.png",
    "IMAGE_REANIM_PEASHOOTER_FRONTLEAF_LEFTTIP": "PeaShooter_frontleaf_lefttip.png",
    "IMAGE_REANIM_PEASHOOTER_FRONTLEAF_RIGHTTIP": "PeaShooter_frontleaf_righttip.png",
    "IMAGE_REANIM_PEASHOOTER_HEAD": "PeaShooter_Head.png",
    "IMAGE_REANIM_PEASHOOTER_HEADLEAF_2RDFARTHEST": "PeaShooter_headleaf_2rdfarthest.png",
    "IMAGE_REANIM_PEASHOOTER_HEADLEAF_3RDFARTHEST": "PeaShooter_headleaf_3rdfarthest.png",
    "IMAGE_REANIM_PEASHOOTER_HEADLEAF_FARTHEST": "PeaShooter_headleaf_farthest.png",
    "IMAGE_REANIM_PEASHOOTER_HEADLEAF_NEAREST": "PeaShooter_headleaf_nearest.png",
    "IMAGE_REANIM_PEASHOOTER_HEADLEAF_TIP_BOTTOM": "PeaShooter_headleaf_tip_bottom.png",
    "IMAGE_REANIM_PEASHOOTER_HEADLEAF_TIP_TOP": "PeaShooter_headleaf_tip_top.png",
    "IMAGE_REANIM_PEASHOOTER_MOUTH": "PeaShooter_mouth.png",
    "IMAGE_REANIM_PEASHOOTER_STALK_BOTTOM": "PeaShooter_stalk_bottom.png",
    "IMAGE_REANIM_PEASHOOTER_STALK_TOP": "PeaShooter_stalk_top.png",
}

# ---------- 创建输出目录 ----------
os.makedirs(output_folder, exist_ok=True)

# ---------- 读取 XML ----------
with open(reanim_path, "r", encoding="utf-8") as f:
    raw_xml = f.read()
fixed_xml = f"<reanim>{raw_xml}</reanim>"
root = ET.fromstring(fixed_xml)

# ---------- 获取帧率 ----------
fps_elem = root.find("fps")
if fps_elem is not None:
    fps = int(fps_elem.text.strip())

# ---------- 构建 track 数据 ----------
track_data = defaultdict(dict)
max_frame = 0

for track in root.findall("track"):
    name_elem = track.find("name")
    if name_elem is None:
        continue
    part_name = name_elem.text.strip()
    frames = track.findall("t")

    for frame_index, t in enumerate(frames):
        if t is None or len(t) == 0:
            continue
        image_id = t.findtext("i", default="")
        if image_id not in image_map:
            continue

        data = {
            "part": part_name,
            "x": float(t.findtext("x", default="0")),
            "y": float(t.findtext("y", default="0")),
            "sx": float(t.findtext("sx", default="1")),
            "sy": float(t.findtext("sy", default="1")),
            "kx": float(t.findtext("kx", default="0")),
            "image_id": image_id
        }
        track_data[part_name][frame_index] = data
        max_frame = max(max_frame, frame_index)

# ---------- 补全每帧所有 part ----------
timeline = defaultdict(list)
last_known = {}

for frame_index in range(max_frame + 1):
    for part_name in track_data:
        if frame_index in track_data[part_name]:
            current = track_data[part_name][frame_index]
            # ✅ 如果 image_id 为空，则表示此帧隐藏此部件（清除）
            if current["image_id"] == "":
                if part_name in last_known:
                    del last_known[part_name]
                continue
            else:
                last_known[part_name] = current
        if part_name in last_known:
            timeline[frame_index].append(last_known[part_name])

# ---------- 合成帧 ----------
def compose_frame(parts):
    canvas = Image.new("RGBA", canvas_size, (0, 0, 0, 0))
    for part in parts:
        image_path = os.path.join(image_folder, image_map[part["image_id"]])
        try:
            img = Image.open(image_path).convert("RGBA")
        except FileNotFoundError:
            continue

        new_w = int(img.width * part["sx"])
        new_h = int(img.height * part["sy"])
        if new_w <= 0 or new_h <= 0:
            continue
        img = img.resize((new_w, new_h), resample=Image.BICUBIC)
        img = img.rotate(-part["kx"], expand=True)

        x = int(part["x"])
        y = int(part["y"])
        canvas.paste(img, (x, y), img)

    return canvas

# ---------- 保存所有帧 ----------
for frame_index in sorted(timeline.keys()):
    img = compose_frame(timeline[frame_index])
    img.save(os.path.join(output_folder, f"frame_{frame_index:03d}.png"))

print(f"✅ 导出完成，共 {len(timeline)} 帧，帧率：{fps}")
