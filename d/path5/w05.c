// Room: /d/path5/w05.c

inherit ROOM;

void create()
{
	set("short", "��ԭС·");
	set("long", @LONG
����һ�������ĸ�ԭС·��·����Щ��б��·�����߶��ǰ�
�˸ߵ��Ӳݣ�����һЩ��֪����Ұ�������ߵ����������ЩΣ
�գ����ɵüӿ��˽Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"w06",
  "northeast" : __DIR__"w04",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
