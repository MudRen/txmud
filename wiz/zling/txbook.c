inherit ITEM;

void create()
{
       set_name("����Ҫ��", ({ "cebook"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("long",
"�Ȿ������ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
"д����һЩ�Ĳ�����̸֮ʲô�á�\n");
        set("value", 800);
        set("material", "paper");
        set("skill", ([
        "name":         "dodge", // �书����
        "exp_required": 10,    // ��������Ҫ����;���.
        "sen_cost":     1,      // ���黨����.
        "difficulty":   22,      // �ο� /cmds/std/study.c
        "max_skill":    600,      // �ܶ�������ߵȼ�.
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
if( (!arg) || !((arg == "cebook") || (arg == "����Ҫ��"))) return notify_fail("��ʲô��\n");
        
if

 (!((string)me->query("family/family_name")=="̤ѩɽׯ")) 
{ message_vision("���ʲô�ط�͵������\n",me); 
        return 1;}

else  
{ return 0;} 
} 
