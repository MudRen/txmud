// zhujiangong.c
// pian

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "铸剑宫");
        set("long", @LONG
这里是雪亭的铸剑宫，一只巨大的融铁炉架在中央，两个大汉
一左一右，推着一只一人多高的风箱。炉中的火苗随着风箱的节奏
飞舞着。这里人来人往，都梦想着打造一把绝世好剑，也好一圆武
林至尊的江湖梦。有一块牌子挂在墙上。(Sign)
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
	"sign" : "牌子上写道：
    		铸 剑 宫 说 明
=======================================================
            命令      原料        辅料      要求等级
-------------------------------------------------------
[青铜发簪] zhu qtfz   一块青铜    一颗木炭  无
[青铜短剑] zhu qtdj   两块青铜    两颗木炭  10级铸造技巧
[青铜手套] zhu qt





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
		return notify_fail("  对不起目前只能提炼青铜，其它暂不开放。\n");
        
        inv = all_inventory(me);
        s=0;
        t=0;
        for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"青铜石"NOR ) {s=s+1;}
		if ( inv[i]->name() == CYN"木炭"NOR ) {t=t+1;}
		}

	if (s<3)
		return notify_fail("  你身上带的青铜石不够，先去找点矿石再说吧。\n");
	if (t<3)
		return notify_fail("  你身上带的木炭不够，先去找点炭火再说吧。\n");
		
	// - 去玩家的原料
	s=3;
	t=3;
	for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"青铜石"NOR )
			{
			if (s>0) 
			{
				message_vision(HIY"$N把一"+inv[i]->query("unit")+inv[i]->name()+HIY"投入提炼炉。\n"NOR,me);
				destruct(inv[i]);
				s=s-1;
				}
			}
		}

	inv = all_inventory(me);

	for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"木炭"NOR )
			{
			if (t>0)
			{	message_vision(HIY"$N把一"+inv[i]->query("unit")+inv[i]->name()+HIY"投入提炼炉。\n"NOR,me);
				destruct(inv[i]);
				t=t-1;
				}
			}
		}
        if(me->query("kee")<20)
        	return notify_fail("  你的力气不足了，还是先休息一下吧。\n");
        if(me->query("gin")<20)
        	return notify_fail("  你的精力不足了，还是先休息一下吧。\n");

//查询玩家有没有挖掘工具。
//    if(!sizeof( inv = filter_array(all_inventory(me),
//		(: $1->is_mine_tool() && $1->tool_can_use() :)) ) )
//		return notify_fail("你身上没有用于挖掘的工具。\n");
//        me->start_busy(2);

        message_vision(HIR"$N只见炉火越来越旺，矿石也渐渐融化了……\n"NOR,me);
        

        // 直接加出结果，减轻系统负担
        i = me->query("kar") + me->query("str") + me->query("int");
        
	//1 是否可以得到xuantie
	if ((sk>250) && (random(sk+i))>( (sk+90)*999/1000) )
	{
		message_vision("$N挖到一颗玄铁石!!!\n", me);
                me->receive_damage("kee", 20);
        	me->receive_damage("gin", 20);
                me->improve_skill("caikuang", 1000);
                ob = new("/d/obj/kuangshi/xuantie_stone");      
                ob->move(me);
                return 1;
        }
        message_vision("$N用铁钳提起坩锅，手竟然哆嗦了一下，铜水洒了一地。\n",me);
        message_vision("$N提炼青铜失败了......\n",me);
        me->receive_damage("kee", 10);
        me->receive_damage("gin", 10);
        me->improve_skill("caikuang", 3);
        return 1;
        
}
                                                                                                                          