// liantiefang.c
//
inherit ROOM;
void create()
{
        set("short", "炼铁坊");
        set("long", @LONG
一只通红的火炉在炼铁坊的中央，旁边有不少的人正在忙忙碌
碌地把矿石、炭扔到炉中冶炼。哇！你身边的老哥居然炼出一大块
玄铁。还发什么呆啊，动手吧！树上挂着一个牌子（Sign）。
LONG
        );
	set(SAFE_ENV, 1);
        set("exits", ([ /* sizeof() == 1 */
                "north" :__DIR__"epath",
        ]));
        set("item_desc", ([
"sign": @TEXT
炼铁坊的使方法:
命令：            说明：    原料：
==========================================================
shao xuantie 	: 烧制玄铁
shao wujin	: 烧制乌金
shao baijin     : 烧制白金
shao hongtie    : 烧制红铁
shao zitie      : 烧制紫铁
shao lvtie      : 烧制绿铁  三颗绿矿石 三颗黑炭
shao qingtong   : 烧制青铜  三颗青铜石 三颗黑炭
=================================Update By pian 2002.11.29

TEXT
        ]) );
}

void init()
{
        add_action("do_shao", "shao");
}
int do_shao(string arg)
{
        object me,ob;
        int i,sk;
        me = this_player();
        sk = me->query_skill("caikuang");
        sk = sk + sk;
        
        if( (arg != "qingtong") && (arg != "lvtie") )
		return notify_fail("你想烧制什么？？\n");
        
        if(me->query("kee")<20)
        	return notify_fail("你的力气不足了，还是先休息一下吧。\n");
        	
        if(me->query("gin")<20)
        	return notify_fail("你的精力不足了，还是先休息一下吧。\n");

//        me->start_busy(2);
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
                me->improve_skill("caikuang", 500);
                ob = new(__DIR__"obj/xuantie_stone");      
                ob->move(me);
                return 1;
        }
        
        //2 是否可以得到wujin
        if ((sk>200) && (random(sk+i))>((sk+85)*999/1000))
	{
		message_vision("$N挖到一颗乌金石!!!\n", me);
                me->receive_damage("kee", 20);
	        me->receive_damage("gin", 20);
                me->improve_skill("caikuang", 100);
                ob = new(__DIR__"obj/wujin_stone");      
                ob->move(me);
                return 1;
        }
        
        //3 是否可以得到baijin
        if ((sk>160) && (random(sk+i))>((sk+80)*999/1000))
	{
		message_vision("$N挖到一颗白金石!!!\n", me);
                me->receive_damage("kee", 15);
        	me->receive_damage("gin", 15);
                me->improve_skill("caikuang", 50);
                ob = new(__DIR__"obj/baijin_stone");      
                ob->move(me);
                return 1;
        }
        
        //4
        if ((sk>120) && (random(sk+i))>((sk+75)*999/1000))
	{
		message_vision("$N挖到一颗红矿石!!!\n", me);
                me->receive_damage("kee", 10);
	        me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 25);
                ob = new(__DIR__"obj/hongkuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //5
        if ((sk>80) && (random(sk+i))>((sk+70)*999/1000))
	{
		message_vision("$N挖到一颗红矿石!!!\n", me);
                me->receive_damage("kee", 10);
        	me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 15);
                ob = new(__DIR__"obj/zikuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //6
        if ((sk>50) && (random(sk+i))>((sk+65)*999/1000))
	{
		message_vision("$N挖到一颗绿矿石!!!\n", me);
                me->receive_damage("kee", 10);
        	me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 10);
                ob = new(__DIR__"obj/lvkuang_stone");      
                ob->move(me);
                return 1;
        }
        
        //7
        if ((random(sk+i))>((sk+70)*9/10))
	{
		message_vision("$N挖到一颗青铜石!!!\n", me);
                me->receive_damage("kee", 10);
	        me->receive_damage("gin", 10);
                me->improve_skill("caikuang", 3);
                ob = new(__DIR__"obj/zikuang_stone");      
                ob->move(me);
                return 1;
        }
        
        message_vision("$N只见从矿坑上掉下来几颗石头，你什么也没有得到。\n",me);
        me->receive_damage("kee", 10);
        me->receive_damage("gin", 10);
        me->improve_skill("caikuang", 1);
        return 1;
        
}