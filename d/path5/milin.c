// Room: /d/path5/milin.c

inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
���߽����֣�ֻ��������ɭɭһ�飬��֪������ʲôΣ�շ�
�������ֵط������ǲ�Ҫ�����ĺá�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" :  __DIR__"milin",
  "west" :   __DIR__"kch23",
  "east" :   __DIR__"milin",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
