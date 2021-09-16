inherit ITEM; 
void create() 
{ set_name("剑法图解", ({ "cebook"}));
set_weight(10);
if( clonep() ) set_default_object(__FILE__);
else 
{ 
set("long", "这是一本看来普通的书，但是书中似乎记载着一套剑法。\n"); 
set("material", "paper");
 set("skill", ([
                        "name":     "sword",
                        "exp_required": 100,
                        "gin_cost":     20,
                        "difficulty":   22,
                        "max_skill":    600,
                        "min_skill":    30,             
]) );
} 
setup(); 
} 



int init () 
{ 
add_action("do_read", "read"); 
} 
int do_read(string arg)
{
object me=this_player(); 
object book=this_object(); 
if( (!arg) || !((arg == "cebook") || (arg == "剑法图解"))) return notify_fail("读什么？\n");
if (!((string)me->query("family/family_name")=="踏雪山庄")) 
{ message_vision("你不是本派弟子,无法从上面获得新知\n",me); }
else 
{ 
if ((int)me->query_skill("sword", 1)<30 ) 
{ 
message_vision("$N按照图解上剑法解释比划了一会，觉得头晕眼花,就赶紧停了下来．\n", me); me->improve_skill("sword", 5+me->query("int")); 
tell_object(me, "你领悟出一些基本剑法技能方面的窍门。\n");
} 
else 
{ 
message_vision("$N你已经完全领会了本书中的奥妙,无法继续提高了。\n", me); 
}
} 
me->receive_damage("kee", (int)me->query("max_kee")*5/100); 
return 1; 
} 
