// Room: /d/hangzhou/house4.c

inherit ROOM;

void create()
{
	set("short", "С̯");
	set("long", @LONG
����һ����ͨ���񷿣������ķ����ں��ݳǵı�Ե�����ܹ�
�ҵ���ס�������һ���ǳ����С�̷�����С���̵����ˣ�����
����ææµµ��ֻ��Ϊ��һ�ٱ������Լ�����һ������ĵط���
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rockroad3",
]));

	setup();
	replace_program(ROOM);
}
