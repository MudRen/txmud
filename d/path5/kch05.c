// Room: /d/path5/kch05.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
��������һ����᫵�С·��·�治ƽ��˵�������������ʯ�顣
������·�ϣ��ܸе���ʲôΣ�գ������߿�Щ�ɣ�ʡ�ý�����֦��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch06",
  "north" : __DIR__"kch04",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
