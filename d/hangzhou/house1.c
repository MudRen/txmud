// Room: /d/hangzhou/house1.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
����һ����ͨ���񷿣������ķ����ں��ݳǵı�Ե�����ܹ�
�ҵ���ס�������һ���ǳ����С�̷�����С���̵����ˣ�����
����ææµµ��ֻ��Ϊ��һ�ٱ������Լ�����һ������ĵط���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"stoneroad1",
]));

	setup();
	replace_program(ROOM);
}
