// Room: /wiz/uudd/path2/k_s04.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ������������Сɽ����ɽ�����Ƶ��ݣ��������ľΪ
�������⣬�㳤���ر�ߴ󣬶������ڱ��ڵ�ɽ�Ⱦ��Ե��ر��
������ʪ����˹��г�����Щ�ߴ����ľ�⣬��Ȼ�Ǵ�ݲ�����
����ֻ��һЩ��̦���׾�֮���ֲ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"k_s05",
  "east" : __DIR__"k_s03",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
