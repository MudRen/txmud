// Room: /u/w/wangs/b/kai51.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�Һܴ�����꣬ʮ����������ڰ�һ�������״���
��ж���������﹩Ӧ��ȫ�ǰ��յĿ��������������ر�ĺ��
�����������������ٴ����ף������Ķ��ѷ��ں���Ŀⷿ�
�����ž���ɽ�Ͻ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai50",
]));

        set("objects",([
        __DIR__"npc/ldboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
