// Room: /d/path5/w02.c

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
  "eastdown" : __DIR__"w01",
  "westup" : __DIR__"w03",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
