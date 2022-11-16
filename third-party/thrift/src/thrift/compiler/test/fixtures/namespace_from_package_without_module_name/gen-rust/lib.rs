// @generated by Thrift for thrift/compiler/test/fixtures/namespace_from_package_without_module_name/src/module.thrift
// This file is probably not the place you want to edit!

#![recursion_limit = "100000000"]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies, clippy::all)]

pub use self::errors::*;
pub use self::types::*;

pub mod types;

#[doc(hidden)]
pub mod dependencies {
}

pub mod services {
    pub mod test_service {
        #[derive(Clone, Debug)]
        pub enum InitExn {
            #[doc(hidden)]
            Success(::std::primitive::i64),
            ApplicationException(::fbthrift::ApplicationException),
        }

        impl ::std::convert::From<::fbthrift::ApplicationException> for InitExn {
            fn from(exn: ::fbthrift::ApplicationException) -> Self {
                Self::ApplicationException(exn)
            }
        }

        impl ::fbthrift::ExceptionInfo for InitExn {
            fn exn_name(&self) -> &'static str {
                match self {
                    Self::Success(_) => panic!("ExceptionInfo::exn_name called on Success"),
                    Self::ApplicationException(aexn) => aexn.exn_name(),
                }
            }

            fn exn_value(&self) -> String {
                match self {
                    Self::Success(_) => panic!("ExceptionInfo::exn_value called on Success"),
                    Self::ApplicationException(aexn) => aexn.exn_value(),
                }
            }

            fn exn_is_declared(&self) -> bool {
                match self {
                    Self::Success(_) => panic!("ExceptionInfo::exn_is_declared called on Success"),
                    Self::ApplicationException(aexn) => aexn.exn_is_declared(),
                }
            }
        }

        impl ::fbthrift::ResultInfo for InitExn {
            fn result_type(&self) -> ::fbthrift::ResultType {
                match self {
                    Self::Success(_) => ::fbthrift::ResultType::Return,
                    Self::ApplicationException(_aexn) => ::fbthrift::ResultType::Exception,
                }
            }
        }

        impl ::fbthrift::GetTType for InitExn {
            const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
        }

        impl<P> ::fbthrift::Serialize<P> for InitExn
        where
            P: ::fbthrift::ProtocolWriter,
        {
            fn write(&self, p: &mut P) {
                if let Self::ApplicationException(aexn) = self {
                    return aexn.write(p);
                }
                p.write_struct_begin("Init");
                match self {
                    Self::Success(inner) => {
                        p.write_field_begin(
                            "Success",
                            ::fbthrift::TType::I64,
                            0i16,
                        );
                        inner.write(p);
                        p.write_field_end();
                    }
                    Self::ApplicationException(_aexn) => unreachable!(),
                }
                p.write_field_stop();
                p.write_struct_end();
            }
        }

        impl<P> ::fbthrift::Deserialize<P> for InitExn
        where
            P: ::fbthrift::ProtocolReader,
        {
            fn read(p: &mut P) -> ::anyhow::Result<Self> {
                static RETURNS: &[::fbthrift::Field] = &[
                    ::fbthrift::Field::new("Success", ::fbthrift::TType::I64, 0),
                ];
                let _ = p.read_struct_begin(|_| ())?;
                let mut once = false;
                let mut alt = ::std::option::Option::None;
                loop {
                    let (_, fty, fid) = p.read_field_begin(|_| (), RETURNS)?;
                    match ((fty, fid as ::std::primitive::i32), once) {
                        ((::fbthrift::TType::Stop, _), _) => {
                            p.read_field_end()?;
                            break;
                        }
                        ((::fbthrift::TType::I64, 0i32), false) => {
                            once = true;
                            alt = ::std::option::Option::Some(Self::Success(::fbthrift::Deserialize::read(p)?));
                        }
                        ((ty, _id), false) => p.skip(ty)?,
                        ((badty, badid), true) => return ::std::result::Result::Err(::std::convert::From::from(
                            ::fbthrift::ApplicationException::new(
                                ::fbthrift::ApplicationExceptionErrorCode::ProtocolError,
                                format!(
                                    "unwanted extra union {} field ty {:?} id {}",
                                    "InitExn",
                                    badty,
                                    badid,
                                ),
                            )
                        )),
                    }
                    p.read_field_end()?;
                }
                p.read_struct_end()?;
                alt.ok_or_else(||
                    ::fbthrift::ApplicationException::new(
                        ::fbthrift::ApplicationExceptionErrorCode::MissingResult,
                        format!("Empty union {}", "InitExn"),
                    )
                    .into(),
                )
            }
        }
    }
}

/// Client implementation for each service in `module`.
pub mod client {

    pub struct TestServiceImpl<P, T, S = ::fbthrift::NoopSpawner> {
        transport: T,
        _phantom: ::std::marker::PhantomData<fn() -> (P, S)>,
    }

    impl<P, T, S> TestServiceImpl<P, T, S>
    where
        P: ::fbthrift::Protocol,
        T: ::fbthrift::Transport,
        P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
        ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        pub fn new(
            transport: T,
        ) -> Self {
            Self {
                transport,
                _phantom: ::std::marker::PhantomData,
            }
        }

        pub fn transport(&self) -> &T {
            &self.transport
        }


        fn _init_impl(
            &self,
            arg_int1: ::std::primitive::i64,
            rpc_options: T::RpcOptions,
        ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::i64, crate::errors::test_service::InitError>> {
            use ::const_cstr::const_cstr;
            use ::tracing::Instrument as _;
            use ::futures::FutureExt as _;

            const_cstr! {
                SERVICE_NAME = "TestService";
                METHOD_NAME = "TestService.init";
            }
            let args = self::Args_TestService_init {
                int1: arg_int1,
                _phantom: ::std::marker::PhantomData,
            };

            let transport = self.transport();

            // need to do call setup outside of async block because T: Transport isn't Send
            let request_env = match ::fbthrift::help::serialize_request_envelope::<P, _>("init", &args) {
                ::std::result::Result::Ok(res) => res,
                ::std::result::Result::Err(err) => return ::futures::future::err(err.into()).boxed(),
            };

            let call = transport
                .call(SERVICE_NAME.as_cstr(), METHOD_NAME.as_cstr(), request_env, rpc_options)
                .instrument(::tracing::trace_span!("call", function = "TestService.init"));

            async move {
                let reply_env = call.await?;

                let de = P::deserializer(reply_env);
                let (res, _de): (::std::result::Result<crate::services::test_service::InitExn, _>, _) =
                    ::fbthrift::help::async_deserialize_response_envelope::<P, _, S>(de).await?;

                let res = match res {
                    ::std::result::Result::Ok(exn) => ::std::convert::From::from(exn),
                    ::std::result::Result::Err(aexn) =>
                        ::std::result::Result::Err(crate::errors::test_service::InitError::ApplicationException(aexn))
                };
                res
            }
            .instrument(::tracing::info_span!("TestService.init"))
            .boxed()
        }
    }

    pub trait TestService: ::std::marker::Send {
        fn init(
            &self,
            arg_int1: ::std::primitive::i64,
        ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::i64, crate::errors::test_service::InitError>>;
    }

    pub trait TestServiceExt<T>: TestService
    where
        T: ::fbthrift::Transport,
    {
        fn init_with_rpc_opts(
            &self,
            arg_int1: ::std::primitive::i64,
            rpc_options: T::RpcOptions,
        ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::i64, crate::errors::test_service::InitError>>;
    }

    struct Args_TestService_init<'a> {
        int1: ::std::primitive::i64,
        _phantom: ::std::marker::PhantomData<&'a ()>,
    }

    impl<'a, P: ::fbthrift::ProtocolWriter> ::fbthrift::Serialize<P> for self::Args_TestService_init<'a> {
        #[inline]
        #[::tracing::instrument(skip_all, level = "trace", name = "serialize_args", fields(method = "TestService.init"))]
        fn write(&self, p: &mut P) {
            p.write_struct_begin("args");
            p.write_field_begin("int1", ::fbthrift::TType::I64, 1i16);
            ::fbthrift::Serialize::write(&self.int1, p);
            p.write_field_end();
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    impl<P, T, S> TestService for TestServiceImpl<P, T, S>
    where
        P: ::fbthrift::Protocol,
        T: ::fbthrift::Transport,
        P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
        ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        fn init(
            &self,
            arg_int1: ::std::primitive::i64,
        ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::i64, crate::errors::test_service::InitError>> {
            let rpc_options = T::RpcOptions::default();
            self._init_impl(
                arg_int1,
                rpc_options,
            )
        }
    }

    impl<P, T, S> TestServiceExt<T> for TestServiceImpl<P, T, S>
    where
        P: ::fbthrift::Protocol,
        T: ::fbthrift::Transport,
        P::Frame: ::fbthrift::Framing<DecBuf = ::fbthrift::FramingDecoded<T>>,
        ::fbthrift::ProtocolEncoded<P>: ::fbthrift::BufMutExt<Final = ::fbthrift::FramingEncodedFinal<T>>,
        P::Deserializer: ::std::marker::Send,
        S: ::fbthrift::help::Spawner,
    {
        fn init_with_rpc_opts(
            &self,
            arg_int1: ::std::primitive::i64,
            rpc_options: T::RpcOptions,
        ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::i64, crate::errors::test_service::InitError>> {
            self._init_impl(
                arg_int1,
                rpc_options,
            )
        }
    }

    impl<'a, S> TestService for S
    where
        S: ::std::convert::AsRef<dyn TestService + 'a>,
        S: ::std::marker::Send,
    {
        fn init(
            &self,
            arg_int1: ::std::primitive::i64,
        ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::i64, crate::errors::test_service::InitError>> {
            self.as_ref().init(
                arg_int1,
            )
        }
    }

    impl<'a, S, T> TestServiceExt<T> for S
    where
        S: ::std::convert::AsRef<dyn TestService + 'a>,
        S: ::std::convert::AsRef<dyn TestServiceExt<T> + 'a>,
        S: ::std::marker::Send,
        T: ::fbthrift::Transport,
    {
        fn init_with_rpc_opts(
            &self,
            arg_int1: ::std::primitive::i64,
            rpc_options: T::RpcOptions,
        ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::i64, crate::errors::test_service::InitError>> {
            <Self as ::std::convert::AsRef<dyn TestServiceExt<T>>>::as_ref(self).init_with_rpc_opts(
                arg_int1,
                rpc_options,
            )
        }
    }

    #[derive(Clone)]
    pub struct make_TestService;

    /// To be called by user directly setting up a client. Avoids
    /// needing ClientFactory trait in scope, avoids unidiomatic
    /// make_Trait name.
    ///
    /// ```
    /// # const _: &str = stringify! {
    /// use bgs::client::BuckGraphService;
    ///
    /// let protocol = BinaryProtocol::new();
    /// let transport = HttpClient::new();
    /// let client = <dyn BuckGraphService>::new(protocol, transport);
    /// # };
    /// ```
    impl dyn TestService {
        pub fn new<P, T>(
            protocol: P,
            transport: T,
        ) -> ::std::sync::Arc<impl TestService + ::std::marker::Send + ::std::marker::Sync + 'static>
        where
            P: ::fbthrift::Protocol<Frame = T>,
            T: ::fbthrift::Transport,
            P::Deserializer: ::std::marker::Send,
        {
            let spawner = ::fbthrift::help::NoopSpawner;
            Self::with_spawner(protocol, transport, spawner)
        }

        pub fn with_spawner<P, T, S>(
            protocol: P,
            transport: T,
            spawner: S,
        ) -> ::std::sync::Arc<impl TestService + ::std::marker::Send + ::std::marker::Sync + 'static>
        where
            P: ::fbthrift::Protocol<Frame = T>,
            T: ::fbthrift::Transport,
            P::Deserializer: ::std::marker::Send,
            S: ::fbthrift::help::Spawner,
        {
            let _ = protocol;
            let _ = spawner;
            ::std::sync::Arc::new(TestServiceImpl::<P, T, S>::new(transport))
        }
    }

    impl<T> dyn TestServiceExt<T>
    where
        T: ::fbthrift::Transport,
    {
        pub fn new<P>(
            protocol: P,
            transport: T,
        ) -> ::std::sync::Arc<impl TestServiceExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
        where
            P: ::fbthrift::Protocol<Frame = T>,
            P::Deserializer: ::std::marker::Send,
        {
            let spawner = ::fbthrift::help::NoopSpawner;
            Self::with_spawner(protocol, transport, spawner)
        }

        pub fn with_spawner<P, S>(
            protocol: P,
            transport: T,
            spawner: S,
        ) -> ::std::sync::Arc<impl TestServiceExt<T> + ::std::marker::Send + ::std::marker::Sync + 'static>
        where
            P: ::fbthrift::Protocol<Frame = T>,
            P::Deserializer: ::std::marker::Send,
            S: ::fbthrift::help::Spawner,
        {
            let _ = protocol;
            let _ = spawner;
            ::std::sync::Arc::new(TestServiceImpl::<P, T, S>::new(transport))
        }
    }

    pub type TestServiceDynClient = <make_TestService as ::fbthrift::ClientFactory>::Api;
    pub type TestServiceClient = ::std::sync::Arc<TestServiceDynClient>;

    /// The same thing, but to be called from generic contexts where we are
    /// working with a type parameter `C: ClientFactory` to produce clients.
    impl ::fbthrift::ClientFactory for make_TestService {
        type Api = dyn TestService + ::std::marker::Send + ::std::marker::Sync + 'static;

        fn with_spawner<P, T, S>(protocol: P, transport: T, spawner: S) -> ::std::sync::Arc<Self::Api>
        where
            P: ::fbthrift::Protocol<Frame = T>,
            T: ::fbthrift::Transport,
            P::Deserializer: ::std::marker::Send,
            S: ::fbthrift::help::Spawner,
        {
            <dyn TestService>::with_spawner(protocol, transport, spawner)
        }
    }

}

/// Server definitions for `module`.
pub mod server {
    #[::async_trait::async_trait]
    pub trait TestService: ::std::marker::Send + ::std::marker::Sync + 'static {
        async fn init(
            &self,
            _int1: ::std::primitive::i64,
        ) -> ::std::result::Result<::std::primitive::i64, crate::services::test_service::InitExn> {
            ::std::result::Result::Err(crate::services::test_service::InitExn::ApplicationException(
                ::fbthrift::ApplicationException::unimplemented_method(
                    "TestService",
                    "init",
                ),
            ))
        }
    }

    #[::async_trait::async_trait]
    impl<T> TestService for ::std::boxed::Box<T>
    where
        T: TestService + Send + Sync + ?Sized,
    {
        async fn init(
            &self,
            int1: ::std::primitive::i64,
        ) -> ::std::result::Result<::std::primitive::i64, crate::services::test_service::InitExn> {
            (**self).init(
                int1, 
            ).await
        }
    }

    /// Processor for TestService's methods.
    #[derive(Clone, Debug)]
    pub struct TestServiceProcessor<P, H, R, RS> {
        service: H,
        supa: ::fbthrift::NullServiceProcessor<P, R, RS>,
        _phantom: ::std::marker::PhantomData<(P, H, R, RS)>,
    }

    struct Args_TestService_init {
        int1: ::std::primitive::i64,
    }
    impl<P: ::fbthrift::ProtocolReader> ::fbthrift::Deserialize<P> for self::Args_TestService_init {
        #[inline]
        #[::tracing::instrument(skip_all, level = "trace", name = "deserialize_args", fields(method = "TestService.init"))]
        fn read(p: &mut P) -> ::anyhow::Result<Self> {
            static ARGS: &[::fbthrift::Field] = &[
                ::fbthrift::Field::new("int1", ::fbthrift::TType::I64, 1),
            ];
            let mut field_int1 = ::std::option::Option::None;
            let _ = p.read_struct_begin(|_| ())?;
            loop {
                let (_, fty, fid) = p.read_field_begin(|_| (), ARGS)?;
                match (fty, fid as ::std::primitive::i32) {
                    (::fbthrift::TType::Stop, _) => break,
                    (::fbthrift::TType::I64, 1) => field_int1 = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                    (fty, _) => p.skip(fty)?,
                }
                p.read_field_end()?;
            }
            p.read_struct_end()?;
            ::std::result::Result::Ok(Self {
                int1: field_int1.ok_or_else(|| ::anyhow::anyhow!("`{}` missing arg `{}`", "TestService.init", "int1"))?,
            })
        }
    }


    impl<P, H, R, RS> TestServiceProcessor<P, H, R, RS>
    where
        P: ::fbthrift::Protocol + ::std::marker::Send + ::std::marker::Sync + 'static,
        P::Frame: ::std::marker::Send + 'static,
        P::Deserializer: ::std::marker::Send,
        H: TestService,
        R: ::fbthrift::RequestContext<Name = ::std::ffi::CStr> + ::std::marker::Send + ::std::marker::Sync + 'static,
        RS: ::fbthrift::ReplyState<P::Frame, RequestContext = R> + ::std::marker::Send + ::std::marker::Sync + 'static,
        <R as ::fbthrift::RequestContext>::ContextStack: ::fbthrift::ContextStack<Name = R::Name, Buffer = ::fbthrift::ProtocolDecoded<P>>
            + ::std::marker::Send + ::std::marker::Sync,
    {
        pub fn new(service: H) -> Self {
            Self {
                service,
                supa: ::fbthrift::NullServiceProcessor::new(),
                _phantom: ::std::marker::PhantomData,
            }
        }

        pub fn into_inner(self) -> H {
            self.service
        }

        #[::tracing::instrument(skip_all, name = "handler", fields(method = "TestService.init"))]
        async fn handle_init<'a>(
            &'a self,
            p: &'a mut P::Deserializer,
            req_ctxt: &R,
            reply_state: ::std::sync::Arc<::std::sync::Mutex<RS>>,
            _seqid: ::std::primitive::u32,
        ) -> ::anyhow::Result<()> {
            use ::const_cstr::const_cstr;
            use ::futures::FutureExt as _;

            const_cstr! {
                SERVICE_NAME = "TestService";
                METHOD_NAME = "TestService.init";
            }
            let mut ctx_stack = req_ctxt.get_context_stack(
                SERVICE_NAME.as_cstr(),
                METHOD_NAME.as_cstr(),
            )?;
            ::fbthrift::ContextStack::pre_read(&mut ctx_stack)?;
            let _args: self::Args_TestService_init = ::fbthrift::Deserialize::read(p)?;
            ::fbthrift::ContextStack::on_read_data(&mut ctx_stack, &::fbthrift::SerializedMessage {
                protocol: P::PROTOCOL_ID,
                method_name: METHOD_NAME.as_cstr(),
                buffer: ::std::marker::PhantomData, // FIXME P::into_buffer(p).reset(),
            })?;
            ::fbthrift::ContextStack::post_read(&mut ctx_stack, 0)?;

            let res = ::std::panic::AssertUnwindSafe(
                self.service.init(
                    _args.int1,
                )
            )
            .catch_unwind()
            .await;

            // nested results - panic catch on the outside, method on the inside
            let res = match res {
                ::std::result::Result::Ok(::std::result::Result::Ok(res)) => {
                    ::tracing::info!("success");
                    crate::services::test_service::InitExn::Success(res)
                }
                ::std::result::Result::Ok(::std::result::Result::Err(crate::services::test_service::InitExn::Success(_))) => {
                    panic!(
                        "{} attempted to return success via error",
                        "init",
                    )
                }
                ::std::result::Result::Ok(::std::result::Result::Err(exn)) => {
                    ::tracing::error!(exception = ?exn);
                    exn
                }
                ::std::result::Result::Err(exn) => {
                    let aexn = ::fbthrift::ApplicationException::handler_panic("TestService.init", exn);
                    crate::services::test_service::InitExn::ApplicationException(aexn)
                }
            };

            let env = ::fbthrift::help::serialize_result_envelope::<P, R, _>(
                "init",
                METHOD_NAME.as_cstr(),
                _seqid,
                req_ctxt,
                &mut ctx_stack,
                res
            )?;
            reply_state.lock().unwrap().send_reply(env);
            Ok(())
        }
    }

    #[::async_trait::async_trait]
    impl<P, H, R, RS> ::fbthrift::ServiceProcessor<P> for TestServiceProcessor<P, H, R, RS>
    where
        P: ::fbthrift::Protocol + ::std::marker::Send + ::std::marker::Sync + 'static,
        P::Deserializer: ::std::marker::Send,
        H: TestService,
        P::Frame: ::std::marker::Send + 'static,
        R: ::fbthrift::RequestContext<Name = ::std::ffi::CStr> + ::std::marker::Send + ::std::marker::Sync + 'static,
        <R as ::fbthrift::RequestContext>::ContextStack: ::fbthrift::ContextStack<Name = R::Name, Buffer = ::fbthrift::ProtocolDecoded<P>>
            + ::std::marker::Send + ::std::marker::Sync + 'static,
        RS: ::fbthrift::ReplyState<P::Frame, RequestContext = R> + ::std::marker::Send + ::std::marker::Sync + 'static
    {
        type RequestContext = R;
        type ReplyState = RS;

        #[inline]
        fn method_idx(&self, name: &[::std::primitive::u8]) -> ::std::result::Result<::std::primitive::usize, ::fbthrift::ApplicationException> {
            match name {
                b"init" => ::std::result::Result::Ok(0usize),
                _ => ::std::result::Result::Err(::fbthrift::ApplicationException::unknown_method()),
            }
        }

        #[allow(clippy::match_single_binding)]
        async fn handle_method(
            &self,
            idx: ::std::primitive::usize,
            _p: &mut P::Deserializer,
            _r: &R,
            _reply_state: ::std::sync::Arc<::std::sync::Mutex<RS>>,
            _seqid: ::std::primitive::u32,
        ) -> ::anyhow::Result<()> {
            match idx {
                0usize => {
                    self.handle_init(_p, _r, _reply_state, _seqid).await
                }
                bad => panic!(
                    "{}: unexpected method idx {}",
                    "TestServiceProcessor",
                    bad
                ),
            }
        }

        #[allow(clippy::match_single_binding)]
        #[inline]
        fn create_interaction_idx(&self, name: &str) -> ::anyhow::Result<::std::primitive::usize> {
            match name {
                _ => ::anyhow::bail!("Unknown interaction"),
            }
        }

        #[allow(clippy::match_single_binding)]
        fn handle_create_interaction(
            &self,
            idx: ::std::primitive::usize,
        ) -> ::anyhow::Result<
            ::std::sync::Arc<dyn ::fbthrift::ThriftService<P::Frame, Handler = (), RequestContext = Self::RequestContext, ReplyState = Self::ReplyState> + ::std::marker::Send + 'static>
        > {
            match idx {
                bad => panic!(
                    "{}: unexpected method idx {}",
                    "TestServiceProcessor",
                    bad
                ),
            }
        }
    }

    #[::async_trait::async_trait]
    impl<P, H, R, RS> ::fbthrift::ThriftService<P::Frame> for TestServiceProcessor<P, H, R, RS>
    where
        P: ::fbthrift::Protocol + ::std::marker::Send + ::std::marker::Sync + 'static,
        P::Deserializer: ::std::marker::Send,
        P::Frame: ::std::marker::Send + 'static,
        H: TestService,
        R: ::fbthrift::RequestContext<Name = ::std::ffi::CStr> + ::std::marker::Send + ::std::marker::Sync + 'static,
        <R as ::fbthrift::RequestContext>::ContextStack: ::fbthrift::ContextStack<Name = R::Name, Buffer = ::fbthrift::ProtocolDecoded<P>>
            + ::std::marker::Send + ::std::marker::Sync + 'static,
        RS: ::fbthrift::ReplyState<P::Frame, RequestContext = R> + ::std::marker::Send + ::std::marker::Sync + 'static
    {
        type Handler = H;
        type RequestContext = R;
        type ReplyState = RS;

        #[tracing::instrument(level="trace", skip_all, fields(service = "TestService"))]
        async fn call(
            &self,
            req: ::fbthrift::ProtocolDecoded<P>,
            req_ctxt: &R,
            reply_state: ::std::sync::Arc<::std::sync::Mutex<RS>>,
        ) -> ::anyhow::Result<()> {
            use ::fbthrift::{BufExt as _, ProtocolReader as _, ServiceProcessor as _};
            let mut p = P::deserializer(req);
            let (idx, mty, seqid) = p.read_message_begin(|name| self.method_idx(name))?;
            if mty != ::fbthrift::MessageType::Call {
                return ::std::result::Result::Err(::std::convert::From::from(::fbthrift::ApplicationException::new(
                    ::fbthrift::ApplicationExceptionErrorCode::InvalidMessageType,
                    format!("message type {:?} not handled", mty)
                )));
            }
            let idx = match idx {
                ::std::result::Result::Ok(idx) => idx,
                ::std::result::Result::Err(_) => {
                    let cur = P::into_buffer(p).reset();
                    return self.supa.call(cur, req_ctxt, reply_state).await;
                }
            };
            self.handle_method(idx, &mut p, req_ctxt, reply_state, seqid).await?;
            p.read_message_end()?;

            Ok(())
        }

        fn create_interaction(
            &self,
            name: &str,
        ) -> ::anyhow::Result<
            ::std::sync::Arc<dyn ::fbthrift::ThriftService<P::Frame, Handler = (), RequestContext = R, ReplyState = RS> + ::std::marker::Send + 'static>
        > {
            use ::fbthrift::{ServiceProcessor as _};
            let idx = self.create_interaction_idx(name);
            let idx = match idx {
                ::anyhow::Result::Ok(idx) => idx,
                ::anyhow::Result::Err(_) => {
                    return self.supa.create_interaction(name);
                }
            };
            self.handle_create_interaction(idx)
        }
    }

    /// Construct a new instance of a TestService service.
    ///
    /// This is called when a new instance of a Thrift service Processor
    /// is needed for a particular Thrift protocol.
    #[::tracing::instrument(level="debug", skip_all, fields(proto = ?proto))]
    pub fn make_TestService_server<F, H, R, RS>(
        proto: ::fbthrift::ProtocolID,
        handler: H,
    ) -> ::std::result::Result<::std::boxed::Box<dyn ::fbthrift::ThriftService<F, Handler = H, RequestContext = R, ReplyState = RS> + ::std::marker::Send + 'static>, ::fbthrift::ApplicationException>
    where
        F: ::fbthrift::Framing + ::std::marker::Send + ::std::marker::Sync + 'static,
        H: TestService,
        R: ::fbthrift::RequestContext<Name = ::std::ffi::CStr> + ::std::marker::Send + ::std::marker::Sync + 'static,
        <R as ::fbthrift::RequestContext>::ContextStack: ::fbthrift::ContextStack<Name = R::Name, Buffer = F::DecBuf> + ::std::marker::Send + ::std::marker::Sync + 'static,
        RS: ::fbthrift::ReplyState<F, RequestContext = R> + ::std::marker::Send + ::std::marker::Sync + 'static
    {
        match proto {
            ::fbthrift::ProtocolID::BinaryProtocol => {
                ::std::result::Result::Ok(::std::boxed::Box::new(TestServiceProcessor::<::fbthrift::BinaryProtocol<F>, H, R, RS>::new(handler)))
            }
            ::fbthrift::ProtocolID::CompactProtocol => {
                ::std::result::Result::Ok(::std::boxed::Box::new(TestServiceProcessor::<::fbthrift::CompactProtocol<F>, H, R, RS>::new(handler)))
            }
            bad => {
                ::tracing::error!(method = "TestService.", invalid_protocol = ?bad);
                ::std::result::Result::Err(::fbthrift::ApplicationException::invalid_protocol(bad))
            }
        }
    }
}

/// Client mocks. For every service, a struct mock::TheService that implements
/// client::TheService.
///
/// As an example of the generated API, for the following thrift service:
///
/// ```thrift
/// service MyService {
///     FunctionResponse myFunction(
///         1: FunctionRequest request,
///     ) throws {
///         1: StorageException s,
///         2: NotFoundException n,
///     ),
///
///     // other functions
/// }
/// ```
///
/// we would end up with this mock object under crate::mock::MyService:
///
/// ```
/// # const _: &str = stringify! {
/// impl crate::client::MyService for MyService<'mock> {...}
///
/// pub struct MyService<'mock> {
///     pub myFunction: myFunction<'mock>,
///     // ...
/// }
///
/// impl dyn crate::client::MyService {
///     pub fn mock<'mock>() -> MyService<'mock>;
/// }
///
/// impl myFunction<'mock> {
///     // directly return the given success response
///     pub fn ret(&self, value: FunctionResponse);
///
///     // invoke closure to compute success response
///     pub fn mock(
///         &self,
///         mock: impl FnMut(FunctionRequest) -> FunctionResponse + Send + Sync + 'mock,
///     );
///
///     // invoke closure to compute response
///     pub fn mock_result(
///         &self,
///         mock: impl FnMut(FunctionRequest) -> Result<FunctionResponse, crate::services::MyService::MyFunctionExn> + Send + Sync + 'mock,
///     );
///
///     // return one of the function's declared exceptions
///     pub fn throw<E>(&self, exception: E)
///     where
///         E: Clone + Into<crate::services::MyService::MyFunctionExn> + Send + Sync + 'mock;
/// }
///
/// impl From<StorageException> for MyFunctionExn {...}
/// impl From<NotFoundException> for MyFunctionExn {...}
/// # };
/// ```
///
/// The intended usage from a test would be:
///
/// ```
/// # const _: &str = stringify! {
/// use std::sync::Arc;
/// use thrift_if::client::MyService;
///
/// #[test]
/// fn test_my_client() {
///     let mock = Arc::new(<dyn MyService>::mock());
///
///     // directly return a success response
///     let resp = FunctionResponse {...};
///     mock.myFunction.ret(resp);
///
///     // or give a closure to compute the success response
///     mock.myFunction.mock(|request| FunctionResponse {...});
///
///     // or throw one of the function's exceptions
///     mock.myFunction.throw(StorageException::ItFailed);
///
///     // or compute a Result (useful if your exceptions aren't Clone)
///     mock.myFunction.mock_result(|request| Err(...));
///
///     let out = do_the_thing(mock).wait().unwrap();
///     assert!(out.what_i_expected());
/// }
///
/// fn do_the_thing(
///     client: Arc<dyn MyService + Send + Sync + 'static>,
/// ) -> impl Future<Item = Out> {...}
/// # };
/// ```
pub mod mock {
    pub struct TestService<'mock> {
        pub init: r#impl::test_service::init<'mock>,
        _marker: ::std::marker::PhantomData<&'mock ()>,
    }

    impl dyn super::client::TestService {
        pub fn mock<'mock>() -> TestService<'mock> {
            TestService {
                init: r#impl::test_service::init::unimplemented(),
                _marker: ::std::marker::PhantomData,
            }
        }
    }

    impl<'mock> super::client::TestService for TestService<'mock> {
        fn init(
            &self,
            arg_int1: ::std::primitive::i64,
        ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::i64, crate::errors::test_service::InitError>> {
            let mut closure = self.init.closure.lock().unwrap();
            let closure: &mut dyn ::std::ops::FnMut(::std::primitive::i64) -> _ = &mut **closure;
            ::std::boxed::Box::pin(::futures::future::ready(closure(arg_int1.clone())))
        }
    }

    mod r#impl {
        pub mod test_service {

            pub struct init<'mock> {
                pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                    dyn ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<
                        ::std::primitive::i64,
                        crate::errors::test_service::InitError,
                    > + ::std::marker::Send + ::std::marker::Sync + 'mock,
                >>,
            }

            #[allow(clippy::redundant_closure)]
            impl<'mock> init<'mock> {
                pub fn unimplemented() -> Self {
                    Self {
                        closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|_: ::std::primitive::i64| panic!(
                            "{}::{} is not mocked",
                            "TestService",
                            "init",
                        ))),
                    }
                }

                pub fn ret(&self, value: ::std::primitive::i64) {
                    self.mock(move |_: ::std::primitive::i64| value.clone());
                }

                pub fn mock(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::std::primitive::i64 + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                    let mut closure = self.closure.lock().unwrap();
                    *closure = ::std::boxed::Box::new(move |int1| ::std::result::Result::Ok(mock(int1)));
                }

                pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<::std::primitive::i64, crate::errors::test_service::InitError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                    let mut closure = self.closure.lock().unwrap();
                    *closure = ::std::boxed::Box::new(move |int1| mock(int1));
                }

                pub fn throw<E>(&self, exception: E)
                where
                    E: ::std::convert::Into<crate::errors::test_service::InitError>,
                    E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
                {
                    let mut closure = self.closure.lock().unwrap();
                    *closure = ::std::boxed::Box::new(move |_: ::std::primitive::i64| ::std::result::Result::Err(exception.clone().into()));
                }
            }
        }
    }
}

/// Error return types.
pub mod errors {
    /// Errors for TestService functions.
    pub mod test_service {

        pub type InitError = ::fbthrift::NonthrowingFunctionError;

        impl ::std::convert::From<crate::services::test_service::InitExn> for
            ::std::result::Result<::std::primitive::i64, InitError>
        {
            fn from(e: crate::services::test_service::InitExn) -> Self {
                match e {
                    crate::services::test_service::InitExn::Success(res) => {
                        ::std::result::Result::Ok(res)
                    }
                    crate::services::test_service::InitExn::ApplicationException(aexn) =>
                        ::std::result::Result::Err(InitError::ApplicationException(aexn)),
                }
            }
        }

    }

}
