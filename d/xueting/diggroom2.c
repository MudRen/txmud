// Diggroom.c  edit by pian
// 给新巫师的参考
inherit ROOM;
void create()
{
	set("short", "东采矿场");
	set("long", @LONG
雪亭北边是一个小型的采矿场，由于刚刚开发，这里的条件还
很简陋。许多人来这里采矿，然后到雪亭镇上的当铺里去出售，换
点钱来生活。（请用digg进行采矿。）
LONG
        );
	set("exits", ([ /* sizeof() == 1 */
//	"southwest" : __DIR__"work",
	"west" : __DIR__"diggroom",
]));
	setup();
}
void init()
{
        add_action("do_digg", "digg");
}
int do_digg()
{
        object me,ob,*inv;
        int i,sk;
        me = this_player();
        sk = me->query_skill("caikuang");
        sk = sk + sk;
        
        if(me->query("kee")<20)
        	return notify_fail("你的力气不足了，还是先休息一下吧。\n");
        if(me->query("gin")<20)
        	return notify_fail("你的精力不足了，还是先休息一下吧。\n");

        //查询玩家有没有挖掘工具。
        if(!sizeof( inv = filter_array(all_inventory(me),
		(: $1->is_mine_tool() && $1->tool_can_use() :)) ) )
		return notify_fail("你身上没有用于挖掘的工具。\n");

        me->start_busy(2);
        message_vision("$N拿起十字镐狠命地向矿坑里刨下去……\n", me);
        message_vision("$N只见从矿坑上掉下来几颗石头，你低头去寻找…\n",me);

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
        
        //2 是否可以得到wujin
        if ((sk>200) && (random(sk+i))>((sk+85)*999/1000))
	{
		message_vision("$N挖到一颗乌金石!!!\n", me);
                me->receive_damage("kee", 20);
	        me->receive_damage("gin", 20);
                me->improve_skill("caikuang", 500);
                ob = new("/d/obj/kuangshi/wujin_stone");      
                ob->move(me);
                return 1;
        }
        
        //3 是否可以得到baijin
        if ((sk>160) && (random(sk+i))>((sk+80)*999/1000))
	{
		message_vision("$N挖到一颗白金石!!!\n", me);
                me->receive_damage("kee", 15);
        	me->receive_damage("gin", 15);
                me->improve_skill("caikuang", 200);
                ob = new("/d/obj/kuangshi/baijin_stone");      
                ob->move(me);
                return 1;
        }
        
        //4
        if ((sk>100) && (random(sk+i))>((sk+75)*999/1000))
	{
		message_vision("$N挖到一颗红矿石!!!\n", me);
                me->receive_damage("kee", 10);
	        me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 150);
                ob = new("/d/obj/kuangshi/hongkuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //5
        if ((sk>50) && (random(sk+i))>((sk+70)*995/1000))
	{
		message_vision("$N挖到一颗紫矿石!!!\n", me);
                me->receive_damage("kee", 10);
        	me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 100);
                ob = new("/d/obj/kuangshi/zikuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //6
        if ((sk>20) && (random(sk+i))>((sk+65)*990/1000))
	{
		message_vision("$N挖到一颗绿矿石!!!\n", me);
                me->receive_damage("kee", 10);
        	me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 30);
                ob = new("/d/obj/kuangshi/lvkuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //7
        if ((random(sk+i))>((sk+70)*9/10))
	{
		message_vision("$N挖到一颗青铜石!!!\n", me);
                me->receive_damage("kee", 10);
	        me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 10);
                ob = new("/d/obj/kuangshi/qingtong_stone");      
                ob->move(me);
                return 1;
        }
        
        message_vision("$N只见矿石明明掉了下来，可是你怎么也找不到。\n",me);
        me->receive_damage("kee", 10);
        me->receive_damage("gin", 10);
        me->improve_skill("caikuang", 3);
        return 1;
        
}

