// Room: /wiz/uudd/path2/k_s09.c

inherit ROOM;

void create()
{
	set("short", "���Ҵ嶫��");
	set("long", @LONG
����һ����ׯ�Ķ��ף�·�Ա�����һ��оɵ�ʯ����������
ǰȥ��ϸ���˿�����ϡ���Էֱ��������š����Ҵ塱�������֣�
ʯ�����׺��񻹿��˺ܶ�С�֣����Ѿ��绯�Ĳ��������ˡ�����
������ʮ�����˼ң����ֻ��һ����С�Ĵ�ׯ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_s10",
  "east" : __DIR__"k_s08",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
