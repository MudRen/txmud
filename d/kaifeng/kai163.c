// Room: /u/w/wangs/b/kai163.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǹ������ֵĽֵ����ֵ��ϼ����˸�ʽ�������ˣ����
���˿���������죬��Ϊ���Ǿ���һ�칤�������ͣ�����������
Ǭ�����·��������Ь�ӣ����ж�����ٶ���Щ�Խڼ��������
ʡ������Ǯ�����������Ѿ����Ծ�����������Ͼ����Ȥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai170",
  "west" : __DIR__"kai164",
  "east" : __DIR__"kai162",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
