// gd_sd 丐帮拜师、升袋系统

#include <ansi.h>

// npc list for gb 1-3 dai promotion
mixed names = ({
       ({
       "旧书","内功心法","百实果","铜棍","木柴","草鞋","埽竹",
       "手绢","海松子","大内伤药","钥匙","灰布袍","玉佩",
       }),
       ({
       "古琴","《达摩剑法入门》","戒刀","砍柴刀","药锄",HIW "风之刃" NOR,
       YEL "普通药材" NOR,HIR "野果" NOR,"兔肉","绳子","铁闸钥匙",
       }),
       ({
        "天山雪莲","毒经总决",HIB "调息手记" NOR,"医药知识","山鸡肉","呼啦草",YEL "小黄花" NOR,
	HIY "铜药炉" NOR,"靖海刺杀令",HIC "小花球" NOR,
       }),
        ({
	"九转灵芝草", HIW "白玉箫" NOR,HIW "小白花" NOR,HIR "暗杀令" NOR,"紫霞玉佩",
	HIR "红货" NOR,RED "密函" NOR,"飞雪寒刃","死牢钥匙",HIY "青龙堂令牌" NOR,
          }),
       ({
        HIR "杀手之剑" NOR,"唐门内功",HIW "白虎堂令牌" NOR,HIR "无名宝刀" NOR,
	}),
});

void killing_object(object who);

string ask_me()
{
        object applicant, me;
	int begging_level,position,htlvl;
	string target;

	applicant = this_player();
	me = this_object();

	if ( applicant->query("class") != "gaibang")
		return RANK_D->query_respect(applicant) +"不是本帮弟子，何有此问？ \n"; 
 
	position = (int)applicant->query("gb_bags");

	if ( applicant->query_temp("promotion_target") )
               return RANK_D->query_respect(applicant) +"快去完成你的任务，好早日升袋！\n";

	begging_level = (int)applicant->query_skill("begging",1);

	if ( begging_level < 80 ) 
		return RANK_D->query_respect(applicant) +"在帮中资历尚浅，不能升袋。\n";

	if ( ( begging_level < 120 ) && ( position == 2 ) )
		return RANK_D->query_respect(applicant) +"要多多加油！\n";

	if ( ( begging_level < 160 ) && ( position == 3 ) )
		return RANK_D->query_respect(applicant) +"要多加努力才能在帮中出人头地。\n";

	if (( begging_level < 200 )&&(position==4))
		return RANK_D->query_respect(applicant) +"还是不能升袋。\n";
	
	htlvl=(int)applicant->query_skill("gaibang-force",1);

	if (( htlvl < 250 ) && (position == 5 ))
		return RANK_D->query_respect(applicant) +"对于武功方面是否过于忽略了？\n";

        if ( position > 5)
		return RANK_D->query_respect(applicant)+"已经技压群雄了，找洪帮主去吧。\n";

        if(applicant->set_temp("promotion_target"))
		return "还不快去？\n";

	target = names[position-1][random(sizeof(names[position-1]))];
	applicant->set_temp("promotion_target", target);
	applicant->set_temp("assigned_by", me->query("name"));
  
		return "好吧，你若要升袋，需得先弄点成绩出来。\n" + "你去把" + target +"给我找来。\n";
}

int promotion_checking(object who, object ob)
{
        int bag,exp;

	if ( who->query("class") != "gaibang" ) 
		return 0;

	if ( ob->query("name") != (string)who->query_temp("promotion_target")) {
		command("say 这东西我要来没用。");
		return 0;
	}

	if  ( ob->is_character()) {
		command("say 这东西我要来没用。");
		return 0;
	}

	if (userp(ob)) {
               command("say " + RANK_D->query_rude(who) + "，居然敢欺骗本舵主，拿命来把！");
               call_out("killing_object",1,who);
               return 0;
	}

	bag=(int)who->query("gb_bags",1);        
        exp=(bag*1000);
	who->add("gb_bags",1);

	who->add("max_force",2*bag);

	who->set_skill("begging",(int)who->query_skill("begging",1) + 1);
	who->set_skill("stealing",(int)who->query_skill("stealing",1) + 1);
	who->add("combat_exp",exp);

        command("applaud " + who->query("id"));
	command("say 干得好！从今天开始，你就是丐帮" + 
		chinese_number(who->query("gb_bags")) +"袋弟子，好好干！\n");

        who->set("title",sprintf("丐帮%s袋弟子",chinese_number(who->query("gb_bags"))) );
	who->delete_temp("assigned_by");
	who->delete_temp("promotion_target");
	return 1;
}      


void killing_object(object who)
{
       object me = this_object();
       me->kill_ob(who);
       who->unconcious();
}


void gb_apprentice(object ob)
{
	if ( (int)ob->query("gb_bags") >= 2 && ob->query("class") != "gaibang" ) 
	{
                command("say 丐帮可容不下你这种背信弃义的小人！");
                return;
        }

        if(ob->query("int") > 24)
        {
                command("say 我派武功需要极好的身体，否则难有所成。\n" +
                RANK_D->query_respect(ob) + "这么聪明，咳...，不如你干点别的吧！");
                return;
        }

        if(ob->query("str") < 24)
        {
                command("say 我派武功需要极好的身体，否则难有所成。\n" +
                RANK_D->query_respect(ob) + "身体这么弱，咳...，不如你干点别的吧！");
                return;
        }

        command("say 好吧，希望" + RANK_D->query_respect(ob) +
        "能好好学习本门武功，将来在江湖中闯出一番作为。");
        command("recruit " + ob->query("id"));

        if (ob->query("class") != "gaibang")
                ob->set("gb_bags", 1);

        if (ob->query("class") == "gaibang" && !ob->query("gb_bags"))
                ob->set("gb_bags", 1);

        ob->set("class", "gaibang");
        ob->set("title",sprintf("丐帮%s袋弟子",
                chinese_number(ob->query("gb_bags"))) );
}
