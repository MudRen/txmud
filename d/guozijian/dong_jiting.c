// Room: /d/guozijian/dong_jiting.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "����ͤ");
	set("long", @LONG
�����Ƕ���ͤ��������һƬ�̵أ�ż����һ��ֻ����������
ȥ�����߷��ӵ��Ŷ����ţ�������һ����ʯ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"yongdao1",
]));

	set("outdoors","guozijian");
	setup();
}

void init()
{
	add_action("do_search","search");
}

int do_search()
{
	object box,me;
	me = this_player();
	if( me->is_busy())
              return notify_fail("����æ���أ�\n");
	me->start_busy(2);
	if( random(10) == 1 ) {
          message_vision("$N�ڲݵ��Ϸ�����ȥ�������ҵ�һ����Կ�ס�\n",me);
	  box = new(__DIR__"obj/key1");
	  box->move(__FILE__);
	}else
          message_vision("$N�ڲݵ��Ϸ�����ȥ����Ȼ������ߣ�����ʲô��û���ҵ���\n",me);
	return 1;
}