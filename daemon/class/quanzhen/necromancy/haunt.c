// haunt.c
#include <ansi.h>
inherit F_CLEAN_UP;
int scribe(object me, object sheet)
{
        object newsheet;
      //  string err;
        if (me->query("class") != "quanzhen")
                return notify_fail("��û�����������ؾ�������ʹ�÷�����\n");
//        if( sheet->name() != "seal" ) 
//                return notify_fail("������ս���У�\n");
        if( me->is_fighting() ) 
                return notify_fail("������ս���У�\n");
        
        if( (int)me->query("mana") < 20 ) 
                return notify_fail("��ķ��������ˣ�\n");
        sheet->set_amount((int)sheet->query_amount() - 1);
        me->save();
        seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "��ʬ׷���" NOR, 
                ({ "haunting sheet", "sheet"}));      
        newsheet->set("attach_func", (: call_other, __FILE__, "do_haunt" :));
        newsheet->move(me);
        me->add("mana", -20);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$Nд��һ����ʬ׷�����\n" NOR, me);
        return 1;
}
int do_haunt(object sheet, object who)
{ 
        string target;
        object dest;
        if( !who->is_zombie() )
                return notify_fail(YEL "��ʬ׷���" NOR 
"ֻ�����ڽ�ʬ���ϡ�\n");
        if( !who->query("possessed") )
                return notify_fail("��������÷�����ס" + who->name() + 
"����ʹ���������\n");
        if( !(sheet->query("targetname")) )
                return notify_fail("�����������" NOR 
"׷˭�Ļꣿ\n");
        target = sheet->query("targetname");
        dest = present(target, environment(who));
        if( !dest ) dest = find_player(target);
        if( !dest ) dest = find_living(target);
        if( objectp(dest) ) {
                who->kill_ob(dest);
                who->set_leader(dest);
           message_vision("$N�۾���Ȼ�������૵�˵����" RED 
"ɱ....��....$n....\n" NOR,
                        who, dest);
                if( environment(dest)==environment(who) ) {
                        dest->fight_ob(who);
                }
        } else {
           message_vision("$N�۾���Ȼ�������૵�˵����" RED 
"ɱ....ɱ....ɱ....\n" NOR,
                        who);
                if( this_player() ) {
                        who->kill_ob(this_player());
                        who->set_leader(this_player());
                        this_player()->fight_ob(who);
                }
        }
        return 1;
}
