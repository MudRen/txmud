// Room: /wiz/uudd/path2/k_s10.c

inherit ROOM;

void create()
{
	set("short", "���С·");
	set("long", @LONG
��Ţ��·�ϵ������˺�����Ľ�ӡ������С����ǣ������·
����ˣ��һ��ũ������ǰ����һλ��ͷ����һ�߰�ર�વس���
���̣�һ�������۾����´������㡣����·�������ż�������ʹ
���С��ׯ�Ե�����һЩ��������һ��ˮ����������һ��������
�ߵ�ũ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"k_s11",
  "east" : __DIR__"k_s09",
  "south" : __DIR__"field",
  "north" : __DIR__"jing",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
