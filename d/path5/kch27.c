// Room: /d/path5/kch27.c

inherit ROOM;

void create()
{
	set("short", "ջ��");
	set("long", @LONG
����һ���˹��޽���ջ������֪������º������������ߵ�
���ֻ������һ�����¼�����������͡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"kch26",
  "eastup" : __DIR__"kch28",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
