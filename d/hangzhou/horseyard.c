// Room: /d/hangzhou/horseyard.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
�����Ǻ��ݳǵ�����ר��Ϊ���ݳǵľ����ṩ��ƥ��ͬʱ
ҲΪƣ�͵������ṩ����ҵ��ʹ�����ܹ����ɵ������ڸ��ء�
������һ����ľ��Χ��Χ����ʮƥ�����׳�Ŀ���
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guotaie3",
]));

	setup();
	replace_program(ROOM);
}
