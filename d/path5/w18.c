// Room: /d/path5/w18.c

inherit ROOM;

void create()
{
	set("short", "��ԭС·");
	set("long", @LONG
����һ�������ĸ�ԭС·��ֻ��ǰ�����Ҷ��ǰ��˶�ߵ���
�ݣ���ʱ�з紵�����ζ��ĸ߲ݾ���󺣲��˴���˷���������
�߾���һ��С��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"w17",
]));
        set("outdoors", "path5");
//        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
