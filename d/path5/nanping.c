// Room: /d/path5/nanping.c

inherit ROOM;

void create()
{
	set("short", "��ƺ��");
	set("long", @LONG
���������ƺ���ˡ����ڴ�����ԭ�����ص��м䣬��������
����ġ��кö��������嶼������ͺ��̽��ס�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kch01",
  "north" : __DIR__"na01",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
