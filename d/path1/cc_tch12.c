// Room: /d/path1/cc_tch12.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ�������·��·�ϵ�����������Խ��Խ���ˣ�ż����
�������˾�������һ�������㲻���е��̵�������·��������һ
ƬƬ�����֣��ּ䲻ʱ����������С�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cc_tch11",
  "north" : __DIR__"cc_tch13",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
