// Room: /d/path5/w11.c

inherit ROOM;

void create()
{
	set("short", "��ԭС·");
	set("long", @LONG
����һ�������ĸ�ԭС·����̧�ۿ�ȥ��ֻ��ǰ�����Ҷ���
���˶�ߵ��Ӳݣ�һ�ۿ������߼ʡ���ʱ�з紵�����ζ��ĸ߲�
����󺣲��˴���˷���ȴ������һ˿�˼���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"w10",
  "westup" : __DIR__"w12",
]));
        set("outdoors", "path5");
//        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
