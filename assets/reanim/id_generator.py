from xml.etree import ElementTree as ET

# 读取原始 .reanim 文件内容
with open("PeaShooter.reanim", "r", encoding="utf-8") as f:
    raw_xml = f.read()

# 加一个根标签包裹内容，形成合法 XML
fixed_xml = f"<reanim>{raw_xml}</reanim>"

# 解析修正后的 XML
root = ET.fromstring(fixed_xml)

# 提取所有 <i> 标签
ids = set()
for i in root.findall(".//i"):
    ids.add(i.text.strip())

# 打印所有图像 ID
for id in sorted(ids):
    print(f'"{id}": "<对应的图片名>",')
