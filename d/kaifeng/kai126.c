// Room: /u/w/wangs/b/kai126.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǿ���Ķ������ˡ���������Ų���Ҳ����ʱ����
�ŵġ������ԵĴ���ȴ�Ǻܴ����������֧�ø߸ߵġ�������
������ǧ��Ʈ��--��������վ�����������ÿ��ֻ������ɫ��
�շ�����ʱ�������������������ȴ�ܶࡣ     
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai125",
]));

        set("objects",([
        __DIR__"npc/dfboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
