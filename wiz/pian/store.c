// zhujiangong.c
// pian

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������ѩͤ����������һֻ�޴������¯�������룬������
һ��һ�ң�����һֻһ�˶�ߵķ��䡣¯�еĻ������ŷ���Ľ���
�����š����������������������Ŵ���һ�Ѿ����ý���Ҳ��һԲ��
������Ľ����Ρ���һ�����ӹ���ǽ�ϡ�(Sign)
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"sstreet1",
]));
//        set("objects", ([
//                __DIR__"npc/foreman": 1,
//                __DIR__"npc/obj/crate": 3,
//        ]));

	set("item_desc", ([ /* sizeof() == 1 */
	"sign" : "������д����
    		�� �� �� ˵ ��
=======================================================
            ����      ԭ��        ����      Ҫ��ȼ�
-------------------------------------------------------
[��ͭ����] zhu qtfz   һ����ͭ    һ��ľ̿  ��
[��ͭ�̽�] zhu qtdj   ������ͭ    ����ľ̿  10�����켼��
[��ͭ����] zhu qt





=======================================================
",
]));
        set("no_fight", 1);
        setup();
}

void init()
{
        add_action("do_tilian", "tilian");
}
int do_tilian(string arg)
{
        object me,ob,*inv;
        int i,s,t,sk;
        me = this_player();
        sk = me->query_skill("caikuang");
        sk = sk + sk;
        
        if( (arg != "qingtong") && (arg != "qt") )
		return notify_fail("  �Բ���Ŀǰֻ��������ͭ�������ݲ����š�\n");
        
        inv = all_inventory(me);
        s=0;
        t=0;
        for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"��ͭʯ"NOR ) {s=s+1;}
		if ( inv[i]->name() == CYN"ľ̿"NOR ) {t=t+1;}
		}

	if (s<3)
		return notify_fail("  �����ϴ�����ͭʯ��������ȥ�ҵ��ʯ��˵�ɡ�\n");
	if (t<3)
		return notify_fail("  �����ϴ���ľ̿��������ȥ�ҵ�̿����˵�ɡ�\n");
		
	// - ȥ��ҵ�ԭ��
	s=3;
	t=3;
	for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"��ͭʯ"NOR )
			{
			if (s>0) 
			{
				message_vision(HIY"$N��һ"+inv[i]->query("unit")+inv[i]->name()+HIY"Ͷ������¯��\n"NOR,me);
				destruct(inv[i]);
				s=s-1;
				}
			}
		}

	inv = all_inventory(me);

	for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"ľ̿"NOR )
			{
			if (t>0)
			{	message_vision(HIY"$N��һ"+inv[i]->query("unit")+inv[i]->name()+HIY"Ͷ������¯��\n"NOR,me);
				destruct(inv[i]);
				t=t-1;
				}
			}
		}
        if(me->query("kee")<20)
        	return notify_fail("  ������������ˣ���������Ϣһ�°ɡ�\n");
        if(me->query("gin")<20)
        	return notify_fail("  ��ľ��������ˣ���������Ϣһ�°ɡ�\n");

//��ѯ�����û���ھ򹤾ߡ�
//    if(!sizeof( inv = filter_array(all_inventory(me),
//		(: $1->is_mine_tool() && $1->tool_can_use() :)) ) )
//		return notify_fail("������û�������ھ�Ĺ��ߡ�\n");
//        me->start_busy(2);

        message_vision(HIR"$Nֻ��¯��Խ��Խ������ʯҲ�����ڻ��ˡ���\n"NOR,me);
        

        // ֱ�Ӽӳ����������ϵͳ����
        i = me->query("kar") + me->query("str") + me->query("int");
        
	//1 �Ƿ���Եõ�xuantie
	if ((sk>250) && (random(sk+i))>( (sk+90)*999/1000) )
	{
		message_vision("$N�ڵ�һ������ʯ!!!\n", me);
                me->receive_damage("kee", 20);
        	me->receive_damage("gin", 20);
                me->improve_skill("caikuang", 1000);
                ob = new("/d/obj/kuangshi/xuantie_stone");      
                ob->move(me);
                return 1;
        }
        message_vision("$N����ǯ����������־�Ȼ������һ�£�ͭˮ����һ�ء�\n",me);
        message_vision("$N������ͭʧ����......\n",me);
        me->receive_damage("kee", 10);
        me->receive_damage("gin", 10);
        me->improve_skill("caikuang", 3);
        return 1;
        
}
                                                                                                                          