// Room: /d/shaolin/luohan1.c

inherit ROOM;

void create()
{
	set("short", "�޺������");
	set("long", @LONG
�����������µ��޺�����ڣ�������ǿ����������ʱ������
���޺������Ὺ������ν�޺�������һ�ٵ��˵����վ�ͨ����
ɮ�ݶ��ģ����а����𷨵�������һ���������Ʋ��ɵ���������
�������������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yongdao2",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
	object who = this_player();

	if(who && !wizardp(who))
		call_out("come_in",1,who);
	return;
}

void come_in(object who)
{
	if(who && environment(who) == this_object())
	{
		tell_object(who,"\n��ֻ����һ��ߴ�������죬һ��ǿ�������������������˳�����\n\n");
		who->move(__DIR__"yongdao2");
	}
}
