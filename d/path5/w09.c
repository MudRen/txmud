// Room: /d/path5/w09.c

inherit ROOM;

void create()
{
	set("short", "��ԭС·");
	set("long", @LONG
����һ�������ĸ�ԭС·��·����Щ��б��·�����߶��ǰ�
�˸ߵ��Ӳݣ�����һЩ��֪����Ұ�������ߵ����������ЩΣ
�գ����ɵüӿ��˽Ų������治ʱ������ˮ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"w08",
  "westup" : __DIR__"w10",
]));

        set("outdoors", "path5");
//        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
