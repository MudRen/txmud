// Room: /d/path5/kch10.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������������ɽ�Ƹ����ն��ˡ���Щͻ����ʯ��
�ͼ�壬���Ź��ߵĻû��������ķ�����ԡ�������ǰ�߰ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"kch09",
  "up" : __DIR__"kch11",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
