# Import python packages
import streamlit as st
import os
from dotenv import load_dotenv
load_dotenv()
# ======= BEGIN VANNA SETUP =======

from vanna.remote import VannaDefault

vanna_model_name="vanna-chatbot"
vanna_api_key = os.getenv("vanna_apikey")
vn = VannaDefault(model=vanna_model_name, api_key=vanna_api_key)

host=os.getenv("HOST")
user="postgres"
password=os.getenv("password")

vn.connect_to_postgres(host=host, dbname='postgres', user=user, password=password, port=5432)

# ======= END VANNA SETUP =======

my_question = st.session_state.get("my_question", default=None)

if my_question is None:
    my_question = st.text_input(
        "Ask me a question about your data",
        key="my_question",
    )
else:
    st.text(my_question)
    
    sql = vn.generate_sql(my_question)

    st.text(sql)

    df = vn.run_sql(sql)    
        
    st.dataframe(df, use_container_width=True)

    code = vn.generate_plotly_code(question=my_question, sql=sql, df=df)

    fig = vn.get_plotly_figure(plotly_code=code, df=df)

    st.plotly_chart(fig, use_container_width=True)
