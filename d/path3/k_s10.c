// Room: /d/path3/k_s10.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������С·�ϣ�����ϡϡ����ĳ���һЩ���ӣ���Щ�Ѿ���
���ˡ���һ��������Ҷ�������������졣�ɴ������߾͵�����
կ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s11",
  "north" : __DIR__"k_s9",
]));
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
