// Room: /d/renyi/renyi2.c

inherit ROOM;

inherit __DIR__"die";

void create()
{
	set("short", "СԺ");
	set("long", @LONG
����һ��������СԺ�ӣ�һ����ʯ��·������䣬����ȫ��
������̲ݳ��÷ǳ������룬���������˾����޼���
LONG
	);

	set(SAFE_ENV, 1);
	set("no_memory", 1);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"renyi1",
  "south" : __DIR__"renyi3",
]));

	set("outdoors", "renyi");

	setup();
}
