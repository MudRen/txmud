// Room: /d/renyi/renyi6.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ��������С��·һֱ�����죬������ï�ܵ����ӣ�
����Զ�������ܿ���һ�ȸߴ�����š�
LONG
	);

	set(SAFE_ENV, 1);
	set("no_memory", 1);

	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"renyi5",
  "southwest" : "/d/path7/lu6",
]));

	set("outdoors", "renyi");

	setup();
	replace_program(ROOM);
}
