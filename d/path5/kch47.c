// Room: /d/path5/kch47.c

inherit ROOM;

void create()
{
	set("short", "ׯ�ڵ�");
	set("long", @LONG
���߹����ֻ�����Զ��ǳɱ�ĵ��һЩũ���������
��æµ�š���϶���м����ª��é���ݣ�����ũ����Ϣ�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"kch46",
  "east" : __DIR__"kch48",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
