// Room: /wiz/uudd/path2/jing.c

inherit ROOM;

void create()
{
	set("short", "ˮ��");
	set("long", @LONG
����һ�ڼ����ˮ������ʯ�����ԲͰ״�ľ�����֧��һ��
���������ο��ɵ��ꤣ�����ھ���������ȥ������ں����ģ�
ʲôҲ��������������Χ������ˮ�ա���ӡ�������������˵���
���ˮ��������������ˮ��(drink)��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"k_s10",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
