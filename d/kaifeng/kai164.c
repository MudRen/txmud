// Room: /u/w/wangs/b/kai164.c

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
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai171",
  "west" : __DIR__"kai165",
  "east" : __DIR__"kai163",
]));

	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
