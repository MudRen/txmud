// Room: /d/shaolin/cangjing1.c

inherit ROOM;

void create()
{
	set("short", "�ؾ���һ��");
	set("long", @LONG
�����������µĲؾ���һ�㣬һ�����һЩ��Ϊ��ͨ�ķ𾭣�
�硶��վ�����������������ÿ���������ʱ���������뾭��
������Ϻ��ٽ����ͻزؾ��󡣶���¥�Ƕ���һЩ��µķ�
���书���塣�м������ո�ǿ��ɮ�������������š���������ʯ
��������¥���϶�¥�ǲؾ����¥��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"cangjing2",
  "west" : __DIR__"yongdao3",
]));

	set(SAFE_ENV,1);
	set("objects", ([
	__DIR__"npc/seng_bing" : 2,
]));

	setup();
}

int valid_leave(object me,string arg)
{
	if( arg =="up"
	&& !wizardp(me)
	&& (me->query("class") != "shaolin"
	|| !me->query("is_bonze")) )
		return notify_fail("ɮ���ȵ��������¹涨�Ǳ��³��ҵ��Ӳ��ý���ؾ����¥����\n");

	else
		return ::valid_leave(me,arg);
}