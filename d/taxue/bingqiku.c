// bingqiku.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "兵器库");
        set("long", @LONG
这里是山庄的兵器库，周围的兵器架上放着很多兵器，刀，剑，矛，戟等
十八般兵器排列整齐。一群山庄弟子正站在架前挑选自己合手的兵刃。有一个
放置着各种兵器的兵器架(jia)摆放在其中。
LONG
        );      	 
	
        set("exits", ([
               "north" : __DIR__"donglang2",               
        ]));
        
        set("objects", ([
		__DIR__"npc/dizi5":1,
        ]));

        set("item_desc", ([
                "jia" : "这是一个专门用来放各种兵器的架子。
里面有：
       刀(blade)，       锤(hammer)，
       枪(spear)，       鞭(whip)，
       杖(staff)，       剑(sword)，
等武器，你可以拿(na)来使用，也可以把不要的兵器放(fang)在上面。
\n"]));
        set("blade_count", 5);            
        set("hammer_count", 5);   
        set("spear_count", 5);      
        set("staff_count", 5);
        set("sword_count", 10);
        set("whip_count", 5);           

        setup(); 
	replace_program(ROOM);
}

void init()
{
        add_action("do_get","na");
        add_action("do_put","fang");
}

int do_get(string arg)
{
       object me,ob;
       string arg1;
       me=this_player();

       if(!arg) return notify_fail("命令格式: na <兵器名称> \n");
       switch (arg){
          case "blade": arg1="/obj/weapon/blade"; break;             
          case "hammer": arg1="/obj/weapon/hammer"; break;   
          case "whip": arg1="/obj/weapon/whip"; break;         
          case "spear": arg1="/obj/weapon/spear"; break;
          case "staff": arg1="/obj/weapon/staff"; break;           
          case "sword": arg1="/d/taxue/obj/sword"; break;
          default :
                 return notify_fail("没有这种兵器。\n");
          }
       if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
       if(query(arg+"_count") < 1)
          return notify_fail("这种兵器已经被拿光了。\n");
       add(arg+"_count", -1);
       ob=new(arg1);
       if(ob) ob->move(me);
       ob->set("value", 10);
       message_vision("$N从兵器架上拿出一"+ob->query("unit")+"$n。\n",me, ob);  
       return 1;
}
int do_put(string arg)
{
       object me, ob;
       string arg1;
       me=this_player();
       if (!arg) return 0;
       if (me->is_busy()) return notify_fail("你正忙着呢。\n");
       if( !objectp(ob = present(arg, me)) )
         return notify_fail("你身上没有这样东西。\n");
       if(!ob->query("weapon_prop")) 
         return notify_fail("你只能将武器放在兵器架上。\n");
       if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

       arg1=ob->query("skill_type");
       switch (arg1){
          case "blade": add("blade_count", 1); break;             
          case "hammer": add("hammer_count", 1); break;   
          case "whip": add("whip_count", 1); break;         
          case "spear": add("spear_count", 1); break;
          case "staff": add("staff_count", 1); break;
          case "sword": add("sword_count", 1); break;           
          default :
                 return notify_fail("你不能将这种兵器放在兵器架上。\n");
          }
       message_vision("$N拿出一"+ob->query("unit")+"$n放在兵器架上。\n",me, ob);  
       destruct(ob);
       return 1;
}

