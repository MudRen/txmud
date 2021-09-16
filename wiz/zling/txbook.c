inherit ITEM;

void create()
{
       set_name("测试要诀", ({ "cebook"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "本");
        set("long",
"这本书上面只有一些字迹模糊的字句，似乎\n"
"写的是一些赌博经验之谈什么得。\n");
        set("value", 800);
        set("material", "paper");
        set("skill", ([
        "name":         "dodge", // 武功名称
        "exp_required": 10,    // 读此书需要的最低经验.
        "sen_cost":     1,      // 读书花的神.
        "difficulty":   22,      // 参看 /cmds/std/study.c
        "max_skill":    600,      // 能读到的最高等级.
]) );
        }
        
 setup();       
}
int init () 
{ 
add_action("do_read", "du"); 
} 

int do_read(string arg)
{
object me=this_player(); 
if( (!arg) || !((arg == "cebook") || (arg == "测试要诀"))) return notify_fail("读什么？\n");
        
if

 (!((string)me->query("family/family_name")=="踏雪山庄")) 
{ message_vision("你从什么地方偷来的书\n",me); 
        return 1;}

else  
{ return 0;} 
} 
