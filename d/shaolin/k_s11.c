// Room: /open/path2/k_s11.c

inherit ROOM;

void create()
{
	set("short", "���С·");
	set("long", @LONG
��Ţ��·�ϵ������˺�����Ľ�ӡ������С����ǣ������·
����ˣ��һ��ũ������ǰ����һλ��ͷ����һ�߰�ર�વس���
���̣�һ�������۾����´������㡣����·�������ż�������ʹ
���С��ׯ�Ե�����һЩ��������һ��СС���ӻ��̣�������һ
���˼ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"k_s12",
  "east" : __DIR__"k_s10",
  "south" : __DIR__"minjv01",
  "north" : __DIR__"shop",
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
