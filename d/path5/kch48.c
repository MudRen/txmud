// Room: /d/path5/kch48.c

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
  "west" : __DIR__"kch47",
  "east" : __DIR__"kch49",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
