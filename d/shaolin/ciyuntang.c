// Room: /d/shaolin/ciyuntang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µĴ����ã��ǽ�����ȵĵط���һЩ��������
����Ů�����ӵ��͵���������ѧϰ�𷨣���Ȼ�еĿ���һֱ����
����е���û��������������ˡ�һ����ɮ����Ŀ�̾�������
�����Ǳ��֣������ǹ㳡�Ҳࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"beilin3",
  "west" : __DIR__"f_square_r",
]));
	set(SAFE_ENV,1);
	set("objects",([
	__DIR__"npc/tidu_seng" : 1,
]));

	setup();
	replace_program(ROOM);
}
