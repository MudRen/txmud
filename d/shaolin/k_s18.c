// Room: /wiz/uudd/path2/k_s18.c

inherit ROOM;

void create()
{
	set("short", "���Ҵ��Ͽ�");
	set("long", @LONG
����һ����ׯ�����ף�·�Ա�����һ��оɵ�ʯ����������
ǰȥ��ϸ���˿�����ϡ���Էֱ��������š����Ҵ塱�������֣�
ʯ�����׺��񻹿��˺ܶ�С�֣����Ѿ��绯�Ĳ��������ˡ�����
������ʮ�����˼ң����ֻ��һ����С�Ĵ�ׯ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s19",
  "north" : __DIR__"k_s17",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
