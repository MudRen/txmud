// Room: /d/path5/w06.c

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
  "west" : __DIR__"w07",
  "northeast" : __DIR__"w05",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
