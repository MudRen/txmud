// Room: /d/path5/kch21.c

inherit ROOM;

void create()
{
	set("short", "���ɽ·");
	set("long", @LONG
����һ����᫵�ɽ·����������������������ǰ���Ĵ�
��������Գ���ড��㲻�ɵô�����־���ע����ܷ�����һ
�С�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"kch22",
  "westdown" : __DIR__"kch20",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
