// Room: /u/w/wangs/a/yu21.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��������Ĵ������ڲ����輫������������һ�ź�ɫ
̴ľ����������·��ž����Ļ�ƿ��һЩ���Ĵ������ı�
�������ҵ��ֻ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yu22",
  "north" : __DIR__"yu5",
]));
        set("objects", ([
        __DIR__"npc/zong1": 1,
]) );
	set("valid_startroom", 1);
	set(SAFE_ENV,1);
	setup();

	load_board("board_feiyu");
}

int valid_leave(object me, string dir)
{
	object ob;

        if (dir =="south")
	{
		if( (me->query("class") != "rain")
		&& !wizardp(me)
		&& objectp(ob = present("qing wu", this_object())) && living(ob) )
			return notify_fail("�������ȵ���վס�����ﲻ����ȥ�ĵط���\n");

                if(sizeof(filter_array(all_inventory(me),(: $1->is_character() :))))
                        return notify_fail("�����ȵ���վס�������������ʲô�˽�ȥ��\n");
	}
	return ::valid_leave(me, dir);
}
