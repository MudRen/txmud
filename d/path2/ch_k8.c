// Room: /d/path2/ch_k8.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��������·��·�����߲�Զ����������̫��ɽ���ˡ�
������ȥ��һƬƬ���������㲻�ɵüӿ��˽Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ch_k7",
  "south" : __DIR__"ch_k9",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
