// Room: /d/path5/nf03.c

inherit ROOM;

void create()
{
	set("short", "�ٻ���");
	set("long", @LONG
����һ�鳤���˸��ֻ��ݵ����֣�����ϵĸ�ʽ�����Ļ���
�У��ܶ��㶼�в�������������һ���������������㡣һȺȺ
�۷��ڻ����з�����ȥ�����Ӻ����ƽʱ���Ĳ�̫һ�������ֵ�
������С��Щ�á�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"nf03",
  "west" : __DIR__"nf02",
  "south" : __DIR__"nf03",
  "north" : __DIR__"nf03",
]));
        set("outdoors", "path5");
        set("altitude", 300);
	setup();
	replace_program(ROOM);
}
