inherit ITEM; 
void create() 
{ set_name("����ͼ��", ({ "cebook"}));
set_weight(10);
if( clonep() ) set_default_object(__FILE__);
else 
{ 
set("long", "����һ��������ͨ���飬���������ƺ�������һ�׽�����\n"); 
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
if( (!arg) || !((arg == "cebook") || (arg == "����ͼ��"))) return notify_fail("��ʲô��\n");
if (!((string)me->query("family/family_name")=="̤ѩɽׯ")) 
{ message_vision("�㲻�Ǳ��ɵ���,�޷�����������֪\n",me); }
else 
{ 
if ((int)me->query_skill("sword", 1)<30 ) 
{ 
message_vision("$N����ͼ���Ͻ������ͱȻ���һ�ᣬ����ͷ���ۻ�,�͸Ͻ�ͣ��������\n", me); me->improve_skill("sword", 5+me->query("int")); 
tell_object(me, "�������һЩ�����������ܷ�������š�\n");
} 
else 
{ 
message_vision("$N���Ѿ���ȫ����˱����еİ���,�޷���������ˡ�\n", me); 
}
} 
me->receive_damage("kee", (int)me->query("max_kee")*5/100); 
return 1; 
} 
