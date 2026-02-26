from PIL import Image
import os

def generate_dialog_frame(target_width, target_height, output_path="output.png"):
    # 资源目录（相对路径）
    base_dir = os.path.join(os.path.dirname(__file__), "../../assets/Items/ui")

    filenames = {
        "topleft": "dialog_topleft.png",
        "topmiddle": "dialog_topmiddle.png",
        "topright": "dialog_topright.png",
        "centerleft": "dialog_centerleft.png",
        "centermiddle": "dialog_centermiddle.png",
        "centerright": "dialog_centerright.png",
        "bottomleft": "dialog_bottomleft.png",
        "bottommiddle": "dialog_bottommiddle.png",
        "bottomright": "dialog_bottomright.png",
    }

    # 加载图像
    tiles = {name: Image.open(os.path.join(base_dir, fname)) for name, fname in filenames.items()}

    # 读取每块的尺寸
    w_tl, h_tl = tiles["topleft"].size
    w_tm, h_tm = tiles["topmiddle"].size
    w_tr, h_tr = tiles["topright"].size

    w_cl, h_cl = tiles["centerleft"].size
    w_cm, h_cm = tiles["centermiddle"].size
    w_cr, h_cr = tiles["centerright"].size

    w_bl, h_bl = tiles["bottomleft"].size
    w_bm, h_bm = tiles["bottommiddle"].size
    w_br, h_br = tiles["bottomright"].size

    # 中间内容区大小（拉伸区域）
    middle_width = target_width - w_tl - w_tr
    middle_height = target_height - h_tl - h_bl

    if middle_width <= 0 or middle_height <= 0:
        raise ValueError("目标尺寸过小，无法容纳所有边框块")

    # 创建输出图像
    output = Image.new("RGBA", (target_width, target_height))

    # === 顶部三块 ===
    output.paste(tiles["topleft"], (0, 0))
    output.paste(tiles["topmiddle"].resize((middle_width, h_tm)), (w_tl, 0))
    output.paste(tiles["topright"], (w_tl + middle_width, 0))

    # === 中部三块 ===
    output.paste(tiles["centerleft"].resize((w_cl, middle_height)), (0, h_tl))
    output.paste(tiles["centermiddle"].resize((middle_width, middle_height)), (w_tl, h_tl))
    output.paste(tiles["centerright"].resize((w_cr, middle_height)), (w_tl + middle_width, h_tr))

    # === 底部三块 ===
    output.paste(tiles["bottomleft"], (0, h_tl + middle_height))
    output.paste(tiles["bottommiddle"].resize((middle_width, h_bm)), (w_bl, h_tl + middle_height))
    output.paste(tiles["bottomright"], (w_bl + middle_width, h_tl + middle_height))

    output.save(output_path)
    print(f"✅ Dialog frame saved to {output_path}")
    return output

if __name__ == "__main__":
    # 测试生成对话框框架
    generate_dialog_frame(800, 600, "../../assets/Items/ui/dialog_frame.png")
    print("Dialog frame generated successfully.")
