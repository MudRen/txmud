// Room: /d/path2/ch_k10.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��������·��·�����߲�Զ����������̫��ɽ���ˡ�
������ȥ��һƬƬ���������㲻�ɵüӿ��˽Ų���ǰ�������
Ͽ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k9",
  "south" : __DIR__"ch_k11",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
