// Room: /d/tangmen/weapon.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������Ƽұ��ı����ң�����ı������ǹ����ŵ���ƽʱ
�����õģ�����Ӧ�о��С�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tulu2",
]));

	set("objects", ([
	WEAPON_DIR"bamboo_sword" : 10,
	WEAPON_DIR"zhui" : 60,
]));

	setup();
	replace_program(ROOM);
}
