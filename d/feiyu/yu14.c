// Room: /u/w/wangs/a/yu14.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������ı����������ܷ��⼸�������ܣ�������
���������ƽʱ���õ�������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"yu13",
]));
        set("objects", ([
        __DIR__"obj/ssword": 5,
                        ]) );

	setup();
	replace_program(ROOM);
}
