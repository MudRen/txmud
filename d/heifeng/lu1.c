// Room: /d/heifeng/lu1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ����᫵���ɽС����·�ߵ��Ӳ��г����˵Ͱ��Ĺ�ľ��
·�ϴ������Ϊ���������ߵ�Ե��ȴ���δ����ż�����ܿ���һ
Щ����ӡ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lu2",
  "westdown" : "/d/path2/shanlu1",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}